/**
Copyright (c) 2012, Brice Videau <brice.videau@imag.fr>
All rights reserved.
      
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    
1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
        
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <CL/opencl.h>
#include <stdio.h>

int main(void) {
  cl_platform_id *platforms;
  cl_uint num_platforms;
  cl_int error;

  error = clGetPlatformIDs(0, NULL, &num_platforms);
  if( error == CL_SUCCESS )
    printf("Found %u platforms!\n", num_platforms);
  else
    exit(-1);
  platforms = (cl_platform_id *)malloc(sizeof(cl_platform_id *) * num_platforms);
  error = clGetPlatformIDs(num_platforms, platforms, NULL);
  cl_uint i;
  for(i=0; i<num_platforms; i++){
    char *platform_vendor;
    size_t param_value_size_ret;

    error = clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, 0, NULL, &param_value_size_ret );
    
    platform_vendor = (char *)malloc(param_value_size_ret);
    clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, param_value_size_ret, platform_vendor, NULL );

    printf("%s\n",platform_vendor);
    free(platform_vendor);
  }
  return 0;
}