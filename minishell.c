char *args[100];
void split_command(char *input) {
   
  }


int main(void)
{
  char * user_input;
  while(1)
  {
  // display minishell> and read the user input
     user_input = readline("minishell> ");
     // if CTRl-D pressed the input = NULL
     if(user_input == NULL)
     {
        printf("Exit shell\n"); // shall we keep it?
        break;     
     }
     if (input[0] == '\0') {
            free(user_input);  
            continue;
        }

       
        add_history(user_input);

        
        split_command(user_input);
       
  }
   free(user_input); 



}
