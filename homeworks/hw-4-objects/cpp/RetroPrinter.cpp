#include <stdio.h>

#include "RetroPrinter.h"

using ::testing::EmptyTestEventListener;
using ::testing::UnitTest;
using ::testing::TestInfo;
using ::testing::TestResult;
using ::testing::TestPartResult;

void RetroPrinter::OnTestProgramStart(const UnitTest& /*unit_test*/ ) { }

  // Called after all test activity ends
void RetroPrinter::OnTestProgramEnd(const UnitTest& unit_test) {
  fprintf(stdout, "RetroGrade> TEST %s\n", unit_test.Passed() ? "PASSED" : "FAILED");
  fflush(stdout);
}

  // called before an individual test case starts
void RetroPrinter::OnTestStart(const TestInfo& test_info) {
  fprintf(stdout,
	  "RetroGrade >\t Test %s.%s starting.\n",
	  test_info.test_case_name(),
	  test_info.name());
  fflush(stdout);
}

  // called after a failed assertion or a SUCCEED() invocation
void RetroPrinter::OnTestPartResult(const TestPartResult& test_part_result) {
  fprintf(stdout,
	  "RetroGrade >\t %s in %s:%d\n",
	  test_part_result.failed() ? "*** Failure" : "Success",
	  test_part_result.file_name(),
	  test_part_result.line_number());
  fflush(stdout);
  if (test_part_result.failed()) {
    fprintf(stdout, "Failure at %s:%d:\n%s\n", 
	    test_part_result.file_name(),
	    test_part_result.line_number(),
	    test_part_result.summary());
    fflush(stdout);
  }
}

// called after a unit test case ends
void RetroPrinter::OnTestEnd(const TestInfo& test_info) {
  const TestResult* result = test_info.result();
  fprintf(stdout,
	  "RetroGrade Result >\t %s: %s\n", test_info.name(), result->Passed() ? "+" : "-");
  fflush(stdout);
}

