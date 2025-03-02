#include "../includes/minishell.h"

void split_command(char *input) {
   char* tmp;
   t_token token;
   tmp = input;
   token.start = 0;
   token.end = 0;
   while(*input == ' ' || *input == '\t')
   {
      input++;
      token.start++;
   }  
   while (*input)
   {
      while(*input == ' ' || *input == '\t')
      {
         input++;
         token.start++;
      }
      token.end = token.start;
  
      if(*input == '|')
      {
         token.value = substr(input, token.start, (token.end - token.start));
         token.next->value = strdup('|');
      }
      else if(*input == '<')
      {
         token.value = substr(input, token.start, (token.end - token.start));
         token.next->value = '<';
      }
      else if(*input == '>')
      {
         token.value = substr(input, token.start,(token.end - token.start));
         token.next->value = '>';
      }
      else if(*input == '>>')
      {
         token.value = substr(input, token.start, (token.end - token.start));
         token.next->value = '>>';
      }
      else if(*input == '<<')
      {
         token.value = substr(input, token.start, (token.end - token.start));
         token.next->value = '<<';
         //shall we add next of next ??
      }
      else if(){
      token.value = substr(input, token.start, (token.end - token.start));

      }
      input++;
      token.end++;
   }
}


  
  



int main(void)
{
  char * user_input;
  while(1)
  {
  // display minishell> and read the user input
     user_input = readline("minishell> ");
     // if CTRl-D pressed the input = NULL
     if(user_input)
     {
        printf("Exit shell\n"); // shall we keep it?
        break;     
     }

     if (user_input[0] == '\0') {
            free(user_input);  
            continue;
        }

      else{
        add_history(user_input);

        
        split_command(user_input);}
       
  }
   free(user_input); 



}
