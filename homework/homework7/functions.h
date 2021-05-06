#define NAME 10
#define DAY 10
#define ENTRY 4
#define EGRESS 4
#define NEWNAME 10
#define NEWDAY 10

typedef struct {
  char* name;
  char* day;
  char* entry;
  char* egress;
  unsigned int pin;
} employee;

struct employee{
 char idemp[5];
 char workDay[20];
 char start[5];
 char end[5];
 
};
struct employee eRegister[200];
