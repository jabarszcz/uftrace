#include "libmcount/dynamic.h"

#include "utils/compiler.h"

__weak int mcount_arch_dynamic_update(struct symtabs *symtabs, char *patch_funcs)
{
	return 0;
}

__weak int enable_sym_dynamic(struct sym *sym)
{
	return 0;
}

__weak int disable_sym_dynamic(struct sym *sym)
{
	return 0;
}

void free_instrumented_funcs(struct list_head *list)
{
	struct instrumented_func *pos, *tmp;
	list_for_each_entry_safe(pos, tmp, list, list) {
		list_del(&pos->list);
		free(pos);
	}
}

__weak struct list_head *get_instrumented_funcs(struct symtab *symtab, struct list_head *ifs)
{
	return NULL;
}
