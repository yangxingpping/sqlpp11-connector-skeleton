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
#include <sqlpp11/exception.h>
#include <sqlpp11/skeleton/bind_result.h>
#include "detail/prepared_statement_handle.h"

#include <iso646.h>
#include <string>


namespace sqlpp
{
	namespace skeleton
	{
		bind_result_t::bind_result_t(const std::shared_ptr<detail::prepared_statement_handle_t>& handle):
			_handle(handle)
		{
			if (_handle and _handle->_debug)
				std::cerr << "Skeleton debug: Constructing bind result, using handle at " << _handle.get() << std::endl;
		}

		void bind_result_t::_bind_boolean_result(size_t index, signed char* value, bool* is_null)
		{
            if (_handle->_debug)
                std::cerr << "odbc debug: binding boolean result " << *value << " at index: " << index << std::endl;

			*(_handle->_skeleton_stmt) >> (char*)value;
			if(_handle->_skeleton_stmt->is_null())
			{
				*is_null = true;
			}
		}

		void bind_result_t::_bind_integral_result(size_t index, int64_t* value, bool* is_null)
		{
            if (_handle->_debug)
                std::cerr << "odbc debug: binding integral result " << *value << " at index: " << index << std::endl;

            *(_handle->_skeleton_stmt) >> *value;
            if (_handle->_skeleton_stmt->is_null())
            {
                *is_null = true;
            }
		}

		void bind_result_t::_bind_floating_point_result(size_t index, double* value, bool* is_null)
		{
            if (_handle->_debug)
                std::cerr << "odbc debug: binding float result " << *value << " at index: " << index << std::endl;

            *(_handle->_skeleton_stmt) >> *value;
            if (_handle->_skeleton_stmt->is_null())
            {
                *is_null = true;
            }
		}

		void bind_result_t::_bind_text_result(size_t index, const char** value, size_t* len)
		{
			assert(value && len);
			otl_long_string f2(*value, *len);

            if (_handle->_debug)
                std::cerr << "odbc debug: binding text result " << *value << " at index: " << index << std::endl;

			*(_handle->_skeleton_stmt) >> f2;
			*len = f2.len();
		}

		void bind_result_t::bind_impl()
		{
            if (_handle->_debug)
                std::cerr << "odbc debug: Binding results for handle at " << _handle.get() << std::endl;

            
		}

		bool bind_result_t::next_impl()
		{
			bool bret = false;
			if(!_handle->_skeleton_stmt->eof())
			{
				bret = true;
			}
			return bret;
		}
	}
}

