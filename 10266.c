#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "grading.h"

#define numQuestion 10
#define ScorePerQuestion 10

int computeScore(char correctAnswer[numQuestion][maxL], 
		 char answer[numQuestion][maxL])
{
  int score = 0;
  for (int i = 0; i < numQuestion; i++) {
    if (strcmp(correctAnswer[i], answer[i]) == 0)
      score += ScorePerQuestion;
  }
  return score;
}

typedef struct submissionScore
{
  Submission submission;
  int score;
} SubmissionScore;

void printOneSubmissionScore(SubmissionScore submissionScore)
{
  printf("Student %d gets %d with Submission %d.\n",
	 submissionScore.submission.studentID, 
	 submissionScore.score,
	 submissionScore.submission.subID);

}

void printSubmissionScore(SubmissionScore submissionScore[],
			  int numSubmission)
{
  for (int i = 0; i < numSubmission; i++) 
    printOneSubmissionScore(submissionScore[i]);
}
    
bool wrongOrder(SubmissionScore a, SubmissionScore b)
{
  return ((a.submission.studentID > b.submission.studentID) ||
	  ((a.submission.studentID == b.submission.studentID) &&
	   (a.submission.subID > b.submission.subID)));
}

void sortSubmissionScore(SubmissionScore submissionScore[], 
			 int numSubmission)
{
  for (int i = numSubmission - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (wrongOrder(submissionScore[j], submissionScore[j + 1])) {
	SubmissionScore temp = submissionScore[j];
	submissionScore[j] = submissionScore[j + 1];
	submissionScore[j + 1] = temp;
      }
}

void printSummary(SubmissionScore submissionScore[], 
		  int numSubmission)
{
  int index = 0;
  while (index < numSubmission) {
    printOneSubmissionScore(submissionScore[index]);
    int maxScore = submissionScore[index].score;
    int thisStudentID = submissionScore[index].submission.studentID;
    index++;
    while (index < numSubmission && 
	   (submissionScore[index].submission.studentID == thisStudentID)) {
      printOneSubmissionScore(submissionScore[index]);
      if (submissionScore[index].score > maxScore)
	maxScore = submissionScore[index].score;
      index++;
    }
    printf("Student %d gets %d in this exam.\n", thisStudentID, maxScore);
  }  
}

void grading(char correctAnswer[10][maxL], Submission* submission, 
	     int numSubmission)
{
  SubmissionScore submissionScore[numSubmission];
  for (int i = 0; i < numSubmission; i++) {
    submissionScore[i].submission = submission[i];
    submissionScore[i].score = 
      computeScore(correctAnswer, submission[i].outputs);
  }
#ifdef DEBUG
  printSubmissionScore(submissionScore, numSubmission);
#endif
  sortSubmissionScore(submissionScore, numSubmission);
#ifdef DEBUG
  printSubmissionScore(submissionScore, numSubmission);
#endif
  printSummary(submissionScore, numSubmission);
}
