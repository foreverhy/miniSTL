// Copyright 2005, Google Inc.
// All rights reserved.
//
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.
//
// Author: wan@google.com (Zhanyong Wan)


// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "gtest/gtest.h"
#include "../vstd/Vector.hpp"
#include <random>


// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>


// Tests Factorial().

// Tests factorial of negative numbers.
//TEST(BINARY_SEARCH_TREE_TEST, PUT) {
  //// This test is named "Negative", and belongs to the "FactorialTest"
  //// test case.
  //using verihy::data_structure::binary_search_tree::binary_search_tree;
  //using verihy::data_structure::binary_search_tree::node;
  //binary_search_tree<char, int> a;

  //a.put('a', 100);
  //a.put('d', 101);
  //a.put('c', 223);
  
  //EXPECT_EQ(a.get('c'), 223);
  //EXPECT_EQ(a.get('d'), 101);
  //EXPECT_EQ(a.get('a'), 100);

  
  ////EXPECT_EQ(1, Factorial(-5));
  ////EXPECT_EQ(1, Factorial(-1));
  ////EXPECT_GT(Factorial(-10), 0);

  //// <TechnicalDetails>
  ////
  //// EXPECT_EQ(expected, actual) is the same as
  ////
  ////   EXPECT_TRUE((expected) == (actual))
  ////
  //// except that it will print both the expected value and the actual
  //// value when the assertion fails.  This is very helpful for
  //// debugging.  Therefore in this case EXPECT_EQ is preferred.
  ////
  //// On the other hand, EXPECT_TRUE accepts any Boolean expression,
  //// and is thus more general.
  ////
  //// </TechnicalDetails>
//}

//TEST(BINARY_SEARCH_TREE, CHANGE){
  //using verihy::data_structure::binary_search_tree::binary_search_tree;
  //using verihy::data_structure::binary_search_tree::node;
  //binary_search_tree<char, int> a;

  //a.put('a', 100);
  //a.put('d', 101);
  //ASSERT_EQ(100, a.get('a'));
  //a.put('a', 223);

  //ASSERT_EQ(223, a.get('a'));
  //a.remove('d');
  

//}

// Tests factorial of 0.
/*TEST(FactorialTest, Zero) {*/
  //EXPECT_EQ(1, Factorial(0));
//}

//// Tests factorial of positive numbers.
//TEST(FactorialTest, Positive) {
  //EXPECT_EQ(1, Factorial(1));
  //EXPECT_EQ(2, Factorial(2));
  //EXPECT_EQ(6, Factorial(3));
  //EXPECT_EQ(40320, Factorial(8));
//}


//// Tests IsPrime()

//// Tests negative input.
//TEST(IsPrimeTest, Negative) {
  //// This test belongs to the IsPrimeTest test case.

  //EXPECT_FALSE(IsPrime(-1));
  //EXPECT_FALSE(IsPrime(-2));
  //EXPECT_FALSE(IsPrime(INT_MIN));
//}

//// Tests some trivial cases.
//TEST(IsPrimeTest, Trivial) {
  //EXPECT_FALSE(IsPrime(0));
  //EXPECT_FALSE(IsPrime(1));
  //EXPECT_TRUE(IsPrime(2));
  //EXPECT_TRUE(IsPrime(3));
//}

//// Tests positive input.
//TEST(IsPrimeTest, Positive) {
  //EXPECT_FALSE(IsPrime(4));
  //EXPECT_TRUE(IsPrime(5));
  //EXPECT_FALSE(IsPrime(6));
  //EXPECT_TRUE(IsPrime(23));
//}

//// Step 3. Call RUN_ALL_TESTS() in main().
////
//// We do this by linking in src/gtest_main.cc file, which consists of
//// a main() function which calls RUN_ALL_TESTS() for us.
////
//// This runs all the tests you've defined, prints the result, and
//// returns 0 if successful, or 1 otherwise.
////
//// Did you notice that we didn't register the tests?  The
//// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
//
#include <string>

TEST(BASIC, PUSH_GET){
    using verihy::vstd::Vector;
    Vector<int> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(i);
    }
    for(int i = 0; i < 100; ++i){
        a[i] = 100 - i;
    }
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(100-i, a[i]);
    }
    Vector<std::string> b;
    for(int i = 0; i < 100; ++i){
        b.push_back(std::to_string(i));
    }
    for(int i = 0; i < 100; ++i){
        b[i] = std::to_string(100-i);
    }
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(std::to_string(100-i), b[i]);
    }

}

TEST(BASIC, ITERATOR){
    using verihy::vstd::Vector;
    Vector<int> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(i);
    }
    for(auto p = a.begin(); p != a.end(); ++p){
        *p = 100-*p;
    }
    int ss = 0;
    for(auto p = a.begin(); p != a.end(); ++ss,p = p + 1){
        ASSERT_EQ(100-ss, *p);
    }
    Vector<std::string> b;
    for(int i = 0; i < 100; ++i){
        b.push_back(std::to_string(i));
    }
    for(int i = 0; i < 100; ++i){
        b[i] = std::to_string(100-i);
    }
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(std::to_string(100-i), b[i]);
    }

}

TEST(CONSTRUCTOR, COPY){
    using verihy::vstd::Vector;
    Vector<std::string> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(std::to_string(i));
    }
    auto ad = a.begin().operator->();
    auto b(a);
    auto bd = b.begin().operator->();
    ASSERT_NE(ad, bd);
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(a[i], b[i]);
    }
    auto c = b;
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(b[i], c[i]);
    }
}
TEST(CONSTRUCTOR, MOVE){
    using verihy::vstd::Vector;
    Vector<std::string> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(std::to_string(i));
    }
    auto ad = a.begin().operator->();
    auto b(std::move(a));
    auto bd = b.begin().operator->();
    ASSERT_EQ(ad, bd);
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(std::to_string(i), b[i]);
    }
    auto c = std::move(b);
    auto cd = c.begin().operator->();
    ASSERT_EQ(bd, cd);
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(std::to_string(i), c[i]);
    }
}
TEST(ASSIGNMENT, COPY){
    using verihy::vstd::Vector;
    Vector<std::string> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(std::to_string(i));
    }
    auto ad = a.begin().operator->();
    Vector<std::string> b;
    b.push_back("nice");
    b = a;
    auto bd = b.begin().operator->();
    ASSERT_NE(ad, bd);
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(std::to_string(i), b[i]);
    }
}
TEST(ASSIGNMENT, MOVE){
    using verihy::vstd::Vector;
    Vector<std::string> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(std::to_string(i));
    }
    auto ad = a.begin().operator->();
    Vector<std::string> b;
    b.push_back("nice");
    b = std::move(a);
    auto bd = b.begin().operator->();
    ASSERT_EQ(ad, bd);
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(std::to_string(i), b[i]);
    }
}

TEST(CAPACITY, EMPTY_SIZE_REVERSE){
    using verihy::vstd::Vector;
    Vector<int> a;
    ASSERT_TRUE(a.empty());
    for(int i = 0; i < 100; ++i){
        a.push_back(i);
    }
    ASSERT_EQ(100, a.size());
    a.reverse();
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(i, a[99 - i]);
    }
    a.clear();
    ASSERT_TRUE(a.empty());

}

TEST(MODIFIER, INSERT){
    using verihy::vstd::Vector;
    using std::string;
    Vector<string> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(std::to_string(i));
    }
    a.insert(a.begin(), "ha");
    ASSERT_EQ("ha", a[0]);
    for(int i = 0; i < 100; ++i){
        ASSERT_EQ(std::to_string(i), a[i + 1]);
    }
    a.erase(a.begin());
    a.insert(a.begin() + 1, "he");
    ASSERT_EQ("he", a[1]);
    ASSERT_EQ("32", a[33]);
    ASSERT_EQ("0", a[0]);

}

TEST(MODIFIER, OTHER){
    using verihy::vstd::Vector;
    using std::string;
    Vector<int> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(i);
    }
    a.pop_back();
    ASSERT_EQ(99, a.size());
    ASSERT_EQ(98, a[98]);
    ASSERT_NE(a.size(), a.capacity());
    a.shrink_to_fit();
    ASSERT_EQ(a.size(), a.capacity());
    for(int i = 0; i < 99; ++i){
        ASSERT_EQ(i, a[i]);
    }

}
