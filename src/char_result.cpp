/*
 * Copyright (c) 2013, Roland Bock
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 *   Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <iostream>
#include <sqlpp11/skeleton/char_result.h>
#include "detail/result_handle.h"

#include <string>
#include <assert.h>


namespace sqlpp
{
	namespace skeleton
	{
		char_result_t::char_result_t()
		{}

		char_result_t::char_result_t(std::unique_ptr<detail::result_handle>&& handle):
			_handle(std::move(handle))
		{
			if (!_handle)
				throw std::runtime_error("Skeleton: Constructing char_result without valid handle");

			if (_handle->debug)
				std::cerr << "Skeleton debug: Constructing result, using handle at " << _handle.get() << std::endl;
		}

		char_result_t::~char_result_t() = default;
		char_result_t::char_result_t(char_result_t&& rhs) = default;
		char_result_t& char_result_t::operator=(char_result_t&&) = default;

		bool char_result_t::next_impl()
		{
            bool bret = true;
            if(_handle->skeleton_res->eof())
            {
                bret = false;
            }
            return bret;
		}

        void char_result_t::_bind_integral_result(size_t index, int64_t* value, bool* is_null)
        {
			assert(value && is_null);
			*(_handle->skeleton_res) >> *value;
		
			if(_handle->skeleton_res->is_null())
			{
				*is_null = true;
			}
        }

        void char_result_t::_bind_boolean_result(size_t index, signed char* value, bool* is_null)
        {
            assert(value && is_null);
            *(_handle->skeleton_res) >> *value;

            if (_handle->skeleton_res->is_null())
            {
                *is_null = true;
            }
        }

        void char_result_t::_bind_floating_point_result(size_t index, double* value, bool* is_null)
        {
            assert(value && is_null);
            *(_handle->skeleton_res) >> *value;

            if (_handle->skeleton_res->is_null())
            {
                *is_null = true;
            }
        }

        void char_result_t::_bind_text_result(size_t index, const char** value, size_t* len)
        {
            *(_handle->skeleton_res) >> (char*)*value;

            if (_handle->skeleton_res->is_null())
            {
               
            }
        }

	}
}

