/**
 * @file complex_calculator.h
 * @author your name (you@domain.com)
 * @brief Functions to perform sorting and display the contact details in data.csv file
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 */
#ifndef __DATA_READ_AND_SORT_H__
#define __DATA_READ_AND_SORT_H__

/**
 * @brief Structure for Data of candidates
 * Name of a candidate
 * Mail-Id of candidate
 * Git link of candidate
 * external pointer to structure
 */
typedef struct info_t
{
   char name[100];
   char mail_id[100];
   char git_link[100];
} info_t;
extern info_t *arr;

/**
 * @brief Read the file
 * @param[in] file_name Pointer to file
 * @return SUCCESS if file reading is completed successfully. Else FAIL.
 */
int read_array(char* file_name);

/**
 * @brief Display the file
 * @param[in] temp Pointer to data in file
 */
int display(info_t *temp);

/**
 * @brief Sort the file
 * @param[in] temp Pointer to data in file
 */
int sort(info_t *temp);
#endif