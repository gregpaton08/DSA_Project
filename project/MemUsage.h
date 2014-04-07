//
//  MemUsage.h
//  project
//
//  Created by Greg Paton on 4/1/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#ifndef project_MemUsage_h
#define project_MemUsage_h

#include <sys/sysctl.h>
#include <mach/mach.h>
#include <cstdio>
#include <stdint.h>
#include <unistd.h>


class MemUsage
{
public:
    /** Total amount of physical memory (bytes) */
    uint64_t physicalMem;
    
    ////////////////////////////////////////////////////////////////////////
    /*! Constructor queries various memory properties of the system
     *///////////////////////////////////////////////////////////////////////
    MemUsage()
    {
        int mib[2];
        mib[0] = CTL_HW;
        mib[1] = HW_MEMSIZE;
        
        size_t returnSize = sizeof(physicalMem);
        if (sysctl(mib, 2, &physicalMem, &returnSize, NULL, 0) == -1) {
            perror("Error in sysctl call");
        }
    }
    
    ////////////////////////////////////////////////////////////////////////
    /*! Queries the kernel for the amount of resident memory in bytes.
     //  @return amount of resident memory (bytes)
     *///////////////////////////////////////////////////////////////////////
    static size_t Usage(void)
    {
        task_t targetTask = mach_task_self();
        struct task_basic_info ti;
        mach_msg_type_number_t count = TASK_BASIC_INFO_64_COUNT;
        
        kern_return_t kr = task_info(targetTask, TASK_BASIC_INFO_64,
                                     (task_info_t) &ti, &count);
        if (kr != KERN_SUCCESS) {
            printf("Kernel returned error during memory usage query");
            return -1;
        }
        
        // On Mac OS X, the resident_size is in bytes, not pages!
        // (This differs from the GNU Mach kernel)
        return ti.resident_size;
    }
};


#endif
