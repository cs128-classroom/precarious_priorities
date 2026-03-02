// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : <Your Name>                  Environment : ubuntu:bionic               //
//  Date ......: <00/00/00>                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "client.hpp"
#include "project.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

const Project kP1(20, "Project 1", 100);
const Project kP2(15, "Project 2", 200);
const Project kP3(10, "Project 3", 300);
const Project kP4(40, "Project 4", 100);
const Project kP5(30, "Project 5", 200);
const Project kP6(20, "Project 6", 300);

TEST_CASE("Project < Operator", "[project]") {
  SECTION("Differing contract value") {
    REQUIRE(kP1 < kP2);
    REQUIRE(kP2 < kP3);
    REQUIRE(kP1 < kP3);

    REQUIRE(!(kP2 < kP1));
    REQUIRE(!(kP3 < kP2));
    REQUIRE(!(kP3 < kP1));
  }

  SECTION("Same contract value; Differing number of users") {
    REQUIRE(kP1 < kP4);
    REQUIRE(kP2 < kP5);
    REQUIRE(kP1 < kP6);

    REQUIRE(!(kP4 < kP1));
    REQUIRE(!(kP5 < kP2));
    REQUIRE(!(kP6 < kP1));
  }
}

TEST_CASE("Client Compare Easy", "[client]") {
  Client a("Microsoft");
  Client b("Apple");

  a += Project(5, "Cortana", 100);
  a += Project(10, "Internet Edge", 1000);
  b += Project(20, "UI", 50);
  b += Project(15, "MacOS", 500);

  REQUIRE_FALSE(a < b);

  Client c("Alphabet");
  c += Project(50, "Gemini", 10000);
  REQUIRE(b < c);
  REQUIRE(a < c);
}

TEST_CASE("Client Compare Hard", "[client]") {
  Client a("Microsoft");
  Client b("Apple");

  REQUIRE_FALSE(a < b);
  a += Project(5, "Cortana", 100);
  a += Project(10, "Internet Edge", 1000);
  REQUIRE(b < a);
  b += Project(20, "UI", 50);
  b += Project(15, "MacOS", 1000);
  REQUIRE(a < b);

  Client c("Alphabet");
  c += Project(20, "Gemini", 50);
  c += Project(15, "Chrome", 1000);
  REQUIRE_FALSE(c < a);
  c += Project(5, "Android", 10);
  REQUIRE(b < c);
}

TEST_CASE("Client +=/-= Operator", "[client]") {
  SECTION("Insert New Project to Current Projects") {
    Client c1("Test Client");

    c1 += kP1;
    REQUIRE(c1.GetCurrentProjects().contains(kP1));

    c1 += kP2;
    REQUIRE(c1.GetCurrentProjects().contains(kP1));
    REQUIRE(c1.GetCurrentProjects().contains(kP2));
  }

  SECTION("Cannot Insert an Existing Project") {
    Client c1("Test Client");

    c1 += kP1;
    REQUIRE(c1.GetCurrentProjects().contains(kP1));

    REQUIRE_THROWS(c1 += kP1);

    REQUIRE(c1.GetCurrentProjects().contains(kP1));
  }

  SECTION("Add a Project and then Move It to Completed") {
    Client c1("Test Client");

    c1 += kP1;
    REQUIRE(c1.GetCurrentProjects().contains(kP1));
    REQUIRE(!c1.GetCompletedProjects().contains(kP1));

    c1 -= kP1;

    REQUIRE(!c1.GetCurrentProjects().contains(kP1));
    REQUIRE(c1.GetCompletedProjects().contains(kP1));
  }

  SECTION(
      "Add a Project and then Move It to Completed and then Move it to "
      "Current") {
    Client c1("Test Client");

    c1 += kP1;
    REQUIRE(c1.GetCurrentProjects().contains(kP1));
    REQUIRE(!c1.GetCompletedProjects().contains(kP1));

    c1 -= kP1;

    REQUIRE(!c1.GetCurrentProjects().contains(kP1));
    REQUIRE(c1.GetCompletedProjects().contains(kP1));

    c1 += kP1;
    REQUIRE(c1.GetCurrentProjects().contains(kP1));
    REQUIRE(!c1.GetCompletedProjects().contains(kP1));
  }

  SECTION("Cannot Remove a Nonexistent Project") {
    Client c1("Test Client");

    REQUIRE_THROWS(c1 -= kP1);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////