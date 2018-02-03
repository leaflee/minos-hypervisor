#ifndef _MVISOR_PERCPU_H_
#define _MVISOR_PERCPU_H_

#include <config/mvisor_config.h>
#include <core/types.h>

extern int get_cpu_id();
extern phy_addr_t percpu_offset[];

#define DEFINE_PER_CPU(type, name) \
	__attribute__((__section__(".__percpu"))) __typeof__(type) per_cpu_##name

#define DECLARE_PER_CPU(type, name) \
	extern __attribute__((__section__(".__percpu"))) __typeof__(type) per_cpu_##name

#define get_per_cpu(name, cpu) \
	(*((__typeof__(per_cpu_##name)*)((unsigned char*)&per_cpu_##name - percpu_offset[0] + percpu_offset[cpu])))

#define get_cpu_var(name) get_per_cpu(name, get_cpu_id())

#endif