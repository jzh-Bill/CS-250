/*This program will read class info from file and help user to find the location *of class
 *author: Zhihao Jin
 */
#include <stdio.h>
#define MAX_CLASS_NAME 16
#define MAX_LOCATION_NAME 24
#define MAX_CLASSES 100
#define TEM_LENGTH 50
#define ONE 1
#define TWO 2


int main(int argc, char *argv[])
{
  //build the class info type
   typedef struct class_info
    {
        char class[MAX_CLASS_NAME];
        char location[MAX_LOCATION_NAME];
        unsigned int enrollment;
    } class_info_t;

    //Build the class_list array
    class_info_t class_list[MAX_CLASSES];
    
    //Declare a tem string to store the line read from file.
    char tem_str[TEM_LENGTH - 1];

    char delims[] = {":\n"};

    int index = 0;

    FILE *fp;

    //File open checker
    if ( (fp = fopen(argv[1], "r")) == NULL )
    {
        printf("Fail to open file!");
        
    }

    
    
    /*Use the loop to read each line from the file and use strtok to
     *store them in the class info_type in class_list array
     */
    unsigned length = 0;
    while( fgets(tem_str,TEM_LENGTH, fp) != NULL )
    {
        char tem_class_name[20];
        strcpy(tem_class_name,strtok(tem_str, delims));
        strcpy(class_list[index].class,tem_class_name);

        char tem_class_location[30];
        strcpy(tem_class_location,strtok(NULL, delims));
        strcpy(class_list[index].location,tem_class_location);

        char tem_enrollment[10];
        strcpy(tem_enrollment,strtok(NULL, delims));

        sscanf(tem_enrollment,"%u", &class_list[index].enrollment);

        index++;
        length++;
    }

    //This the ender is used to end the infinite loop with command ctr + d
    int ender;

    //Infinite loop to let user ask with infinite times.
    while (ONE != TWO)
    {
      printf("Enter the name of the class:");

      //If user input EOF(ctr + d), then break the loop.
      int res = scanf("%d",&ender);
      if(res == EOF)
      {
	printf("\n");
	break;
      }
      
      char tem_class_name[MAX_CLASS_NAME];

      fgets(tem_class_name,MAX_CLASS_NAME,stdin);

      char  small_deli[] = {"\n"};
      char tem_class_name_2[20];

      strcpy(tem_class_name_2,strtok(tem_class_name,small_deli ));
 
      //This is result of comparison, if the loop find the name, it should be 0
      int cmp_result;
      
      int loop_counter = 0;

      //If find the class name, it will be change to 1, otherwise -1
      int find_or_not = 0;

      
      for(loop_counter; loop_counter < length; loop_counter++)
      {
	//Find the name and turn cmp_result into 0,otherwise not 0.
	cmp_result = strcmp(class_list[loop_counter].class , tem_class_name_2);

	//If the loop find the class name, break the loop.
	if(cmp_result == 0)
	{
	  //Change the find_or_not value to 1
	  find_or_not = 1;
	  break;
	}
	else if(cmp_result != 0 && loop_counter == (length - 1))
	{
	  //If it doesn't it, change the find_or_not value to -1.
	  find_or_not = -1;
	}
      }

      //Output result based no the value of find_or_not
      if( find_or_not == 1)
      {
	find_or_not = 0;
	printf("The class %s meets in %s with %u people.",tem_class_name_2,
	       class_list[loop_counter].location, class_list[loop_counter].
	       enrollment);
      }
      else if(find_or_not == -1)
      {
	find_or_not = 0;
	printf("There is no class named %s",tem_class_name_2);
      }
      printf("\n");
    }
   return 0;
}



