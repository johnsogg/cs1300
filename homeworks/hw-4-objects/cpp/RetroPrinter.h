#include <stdio.h>

#include "gtest/gtest.h"

using ::testing::EmptyTestEventListener;
using ::testing::UnitTest;
using ::testing::TestInfo;
using ::testing::TestPartResult;

class RetroPrinter : public EmptyTestEventListener {
private:
  virtual void OnTestProgramStart(const UnitTest& /*unit_test*/ );

  // Called after all test activity ends
  virtual void OnTestProgramEnd(const UnitTest& /*unit_test*/);

  // called before an individual test case starts
  virtual void OnTestStart(const TestInfo& /* unit_test */);

  // called after a failed assertion or a SUCCEED() invocation
  virtual void OnTestPartResult(const TestPartResult& test_part_result);

  // called after a unit test case ends
  virtual void OnTestEnd(const TestInfo& test_info);

}; // class RetroPrinter
