#ifndef PARSER_VALIDATOR_H_
#define PARSER_VALIDATOR_H_

int eol_validator(const char * current);
int num_validator(const char * current);
int float_validator(const char * current);
int name_validator(const char * current);
int equal_validator(const char * current);
int blockstart_validator(const char * current);
int blockend_validator(const char * current);
int areastart_validator(const char * current);
int axe_validator(const char * current);

#endif