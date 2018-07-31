/*
 * Copyright (C) 2018 Min Le (lemin9538@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <minos/minos.h>
#include <asm/svccc.h>
#include <minos/sched.h>
#include <minos/virt.h>
#include <minos/vm.h>
#include <minos/hypercall.h>

static int vcpu_hvc_handler(gp_regs *c, uint32_t id, uint64_t *args)
{
	return 0;
}

static int vm_hvc_handler(gp_regs *c, uint32_t id, uint64_t *args)
{
	int vmid = -1;
	unsigned long addr;
	unsigned long size;

	switch (id) {
	case HVC_VM_CREATE:
		vmid = create_new_vm((struct vm_info *)args[0]);
		HVC_RET1(c, vmid);
		break;
	case HVC_VM_DESTORY:
		break;
	case HVC_VM_RESTART:
		break;
	case HVC_VM_POWER_UP:
		break;
	case HVC_VM_POWER_DOWN:
		break;
	case HVC_VM_MMAP:
		addr = create_vm_mmap((int)args[0], args[1], args[2]);
		HVC_RET1(c, addr);
		break;
	case HVC_VM_UNMMAP:
		destory_vm_mmap((int)args[0]);
		HVC_RET1(c, 0);
		break;

	case HVC_VM_GET_MMAP_INFO:
		addr = get_vm_mmap_info((int)args[0], &size);
		HVC_RET2(c, addr, size);
	}

	return 0;
}

static int pm_hvc_handler(gp_regs *c, uint32_t id, uint64_t *args)
{
	return 0;
}

static int misc_hvc_handler(gp_regs *c, uint32_t id, uint64_t *args)
{
	return 0;
}

DEFINE_HVC_HANDLER("vcpu_hvc_handler", HVC_TYPE_HVC_VCPU,
		HVC_TYPE_HVC_VM, vcpu_hvc_handler);

DEFINE_HVC_HANDLER("vm_hvc_handler", HVC_TYPE_HVC_VM,
		HVC_TYPE_HVC_VM, vm_hvc_handler);

DEFINE_HVC_HANDLER("pm_hvc_handler", HVC_TYPE_HVC_PM,
		HVC_TYPE_HVC_PM, pm_hvc_handler);

DEFINE_HVC_HANDLER("misc_hvc_handler", HVC_TYPE_HVC_MISC,
		HVC_TYPE_HVC_MISC, misc_hvc_handler);