#include <dlfcn.h>
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ladspa.h>
#include "plugin.h"

int plugin_init (state_t *state, const char * plugin_file, int index)
{
	const char *error;
	int err = 0;

	void* handle = dlopen(plugin_file, RTLD_LAZY);
	if (handle == NULL) {
		printf ("%s\n", dlerror ());
		exit (1) ;
	}
	
	//~ *(void **)(&f) = dlsym (handle, "ladspa_descriptor") ;
	//~ (*f) ();

	LADSPA_Descriptor_Function fDescriptorFunction;
	dlerror();
	
	fDescriptorFunction = (LADSPA_Descriptor_Function)dlsym(handle,
							"ladspa_descriptor");

	const LADSPA_Descriptor * psDescriptor;
	LADSPA_Descriptor_Function pfDescriptorFunction;

	state -> descriptor = fDescriptorFunction (0);
	return 0;
}

