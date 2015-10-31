#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf_in[32768];
char buf_out_cmp[32768];
char cmd[32768];

void stop_base(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] == '\n')
    {
      str[i] = 0;
      return ;
    }
    i++;
  }
}

int write_to_file(char *filename, char *buf)
{
  FILE *f = fopen(filename, "w+");
  if (f == NULL)
    return (0);
  fwrite(buf, strlen(buf), 1, f);
  fclose(f);
  return (1);
}

int	main(int argc, char **argv)
{
  FILE* f;
  int i;
  char *base;
  int in_size;
  int line;
  int fr_res;

  if (argc < 2)
    return (1);
  strcpy(buf_in, argv[1]);
  buf_in[strlen(argv[1])] = 0;
  if (argc == 3)
    base = argv[2];
  else
    base = "0123456789";
  if (!write_to_file("~test_in", buf_in))
    return (1);
  in_size = strlen(buf_in);
  sprintf(cmd, "cat ~test_in | ./calc \"%s\" \"()+-*/%\" %d > ~test_out", base, in_size);
  system(cmd);
  FILE *out = fopen("~test_out", "r");
  fr_res = fread(buf_out_cmp, 1, 32768, out);
  buf_out_cmp[fr_res] = 0;
  fclose(out);
  printf("%s\n", buf_out_cmp);
  return (0);
}
