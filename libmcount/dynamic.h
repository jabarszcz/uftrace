#ifndef _MCOUNT_DYNAMIC_H_
#define _MCOUNT_DYNAMIC_H_

#include <stddef.h>

#include "utils/symbol.h"
#include "utils/list.h"

struct instrumented_func {
	struct list_head list;
	int active;
	struct sym *sym;
};

int mcount_arch_dynamic_update(struct symtabs *symtabs, char *patch_funcs);

int enable_sym_dynamic(struct sym *sym);
int disable_sym_dynamic(struct sym *sym);
void free_instrumented_funcs(struct list_head *list);
struct list_head *get_instrumented_funcs(struct symtab *symtab, struct list_head *ifs);

#endif // _MCOUNT_DYNAMIC_H_
