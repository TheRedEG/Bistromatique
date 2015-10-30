#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf_in[32768];
char buf_out[32768];
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

  if (argc != 2)
    return (1);
  f = fopen(argv[1], "r");
  if (f == NULL)
    return (1);
  line = 2;
  while (fgets(buf_in, sizeof(buf_in), f))
  {
    if (!fgets(buf_out, sizeof(buf_out), f))
      return (1);
    for (i = 0; i < sizeof(buf_out); i++)
    {
      if (buf_out[i] == '\0' || buf_out[i] == '\n')
      {
	buf_out[i] = 0;
	break;
      }
    }
    for (i = 0; i < sizeof(buf_in); i++)
    {
      if (buf_in[i] == '\0' || buf_in[i] == '\n')
      {
	buf_in[i] = 0;
	base = "0123456789";
	break;
      }
      else if (buf_in[i] == ' ')
      {
	buf_in[i] = 0;
	base = buf_in + i + 1;
	stop_base(base);
	break;
      }
    }
    if (!write_to_file("~test_in", buf_in))
      return (1);
    in_size = strlen(buf_in);
    sprintf(cmd, "cat ~test_in | ./calc \"%s\" \"()+-*/%\" %d > ~test_out", base, in_size);
    system(cmd);
    FILE *out = fopen("~test_out", "r");
    fr_res = fread(buf_out_cmp, 1, 32768, out);
    buf_out_cmp[fr_res] = 0;
    fclose(out);
    if (strcmp(buf_out_cmp, buf_out) != 0)
    {
      printf("Test failed at line %d:\n\t%s\ngives %s instead of %s\n", line, buf_in, buf_out_cmp, buf_out);
      fclose(f);
      return (2);
    }
    line += 2;
  }
  fclose(f);
  printf("All tests ok\n");
  return (0);
}
