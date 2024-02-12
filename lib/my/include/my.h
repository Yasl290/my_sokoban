/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** All mylib prototypes.
*/
#include <stdarg.h>
#include <sys/stat.h>
#include <stdbool.h>


#ifndef MY_H_
    #define MY_H_


struct my_flags {
    int minus;
    int plus;
    int space;
    int diese;
    int zero;
};

typedef struct get_flag {
    struct my_flags my_flag;
    int my_width;
    int my_precision;
    char my_length;
    char my_specifier;
} get_flag_t;

int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(const char *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_strlen_bis(char const *str);
int my_is_prime_bis(int nb);
char **my_str_to_word_array(char const *str);
char **copy_array(char const *str, char **array);
int my_is_alphanum(char c);
char my_charlowcase(char c);
int my_printf(const char *format, ...);
int print_d(const char *format, va_list list, int i, get_flag_t flag);
int print_i(const char *format, va_list list, int i, get_flag_t flag);
int print_s(const char *format, va_list list, int i, get_flag_t flag);
int print_c(const char *format, va_list list, int i, get_flag_t flag);
int print_percent(const char *format, va_list list, int i, get_flag_t flag);
int print_p(const char *format, va_list list, int i, get_flag_t flag);
int my_unsigned_nbr(unsigned int nb);
int print_u(const char *specifier, va_list list, int i, get_flag_t flag);
int print_hex_address(void *ptr);
int print_o(const char *specifier, va_list list, int i, get_flag_t flag);
int my_unsigned_o(unsigned int nb);
int print_lowerx(const char *specifier, va_list list, int i, get_flag_t flag);
int my_unsigned_x(unsigned int nb);
int print_upperx(const char *specifier, va_list list, int i, get_flag_t flag);
int my_unsigned_upperx(unsigned int nb);
int loop_upperx(unsigned int nb, char *hexupper, int *y, int count);
int loop_x(unsigned int nb, char *hexlower, int *y, int count);
get_flag_t get_all_flags(const char *format, int *i);
int front_padding_int(get_flag_t flag, int arg_int);
int back_padding_int(get_flag_t flag, int arg_int);
int front_padding_str(get_flag_t flag, char *arg_str);
int back_padding_str(get_flag_t flag, char *arg_str);
int front_padding_char(get_flag_t flag);
int back_padding_char(get_flag_t flag);
int print_space_plus(get_flag_t flag, int arg_int);
int printf_f(double nb, int precision);
int print_f(const char *specifier, va_list list, int i, get_flag_t flag);
int plus_flag(get_flag_t flag, int arg_int);
int space_flag(get_flag_t flag, int arg_int);
int loop_printf_f(double *nb, int *precision);
int print_upperf(const char *specifier, va_list list, int i, get_flag_t flag);
int printf_upperf(double nb, int precision);
int loop_printf_upperf(double *nb, int *precision);

/*
FUNCTIONS FOR THE MY_SOKOBAN
*/
int file_rp(const char *fpth);

void buf_er(char **buffer, int *f, const char *fpth, struct stat *file_stat);

void calculate_dimensions(const char *buffer, int *rows, int *cols);




typedef struct {
    int **map;
    int **squares;
    int rows;
    int cols;
    int *max_size;
    int *max_i;
    int *max_j;
} msf;


typedef struct {
    int **map;
    int **squares;
    int rows;
    int cols;
} sql;

typedef struct {
    int *max_size;
    int *max_i;
    int *max_j;
} msp;


typedef struct {
    int row;
    int col;
    int rows;
    int cols;
} MapParams;

int window_curses(char *argv[]);

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position player;
    Position *boxes;
    Position *targets;
    int box_count;
    int target_count;
    int rows;
    int cols;
    char *original_map;  // Ajouter pour stocker l'état initial de la carte
} GameState;


typedef struct {
    int rows;
    int cols;
} MD;

typedef struct {
    int box_capacity;
    int target_capacity;
} GC_T;

typedef struct {
    char **buffer;
    int *fileDescriptor;
    GameState *state;
    int **map;
} GD_T;

typedef struct {
    int **map;
    int rows;
    int cols;
} Map;

typedef struct GameContext {
    int **map;
    GameState *state;
    int rows;
    int cols;
} GameContext;

void fill_map(const char *buffer, int ***map, MD dimensions, GameState *state);


void init_game_state(GameState *state, int rows, int cols, GC_T capacities);

int check_game_state(const int **map, const GameState *state);



    #define UP 0
    #define DOWN 1
    #define LEFT 2
    #define RIGHT 3

int handle_movement(int ch, int ***map, GameState *state);

int game_loop(char *argv[]);

void print_map(int **map, int rows, int cols);

int is_box_blocked(const int **map, Position box, int rows, int cols);


void proc_map(char *buffer, int ***map, MD dimensions, GameState *state);

bool game_over(const int **map, GameState *state, int rows, int cols);

void buff(const char *buffer, int ***map, GameState *state, MapParams *params);

void handle_char(int val, int ***map, GameState *state, MapParams *params);

void update_position(char c, MapParams *params);


void m_ap(const char *buffer, int ***map, GameState *state, MD dim);

int char_to_int(char c);

void update_game_state(int val, GameState *state, MapParams *params);

void free_resources(int ***map, GameState *state, int rows);

int move_player(int ***map, GameState *state, int direction);

void handle_box_target(int val, GameState *state, MapParams *params);

int gest(char **buffer, struct stat *fS, int *fileDescriptor, const char *fP);


#endif /* MY_H_ */
