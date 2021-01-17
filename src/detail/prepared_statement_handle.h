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

#pragma once

#include <assert.h>

#include "otl/otlv4.h"

namespace sqlpp
{
	namespace skeleton
	{
		// FIXME
		using SKELETON_STMT = std::shared_ptr<otl_stream>;

		namespace detail
		{
			struct prepared_statement_handle_t
			{
				SKELETON_STMT _skeleton_stmt;
				bool _debug;

				size_t _no_params;
				size_t _no_columns;

				prepared_statement_handle_t(SKELETON_STMT stmt, size_t no_of_parameters, size_t no_of_columns, bool debug_)
				{
                    assert(stmt);
                    _skeleton_stmt = stmt;
                    _debug = debug_;
                    _no_params = no_of_parameters;
                    _no_columns = no_of_columns;
                }
				prepared_statement_handle_t(const prepared_statement_handle_t&) = delete;
				prepared_statement_handle_t(prepared_statement_handle_t&&) = default;
				prepared_statement_handle_t& operator=(const prepared_statement_handle_t&) = delete;
				prepared_statement_handle_t& operator=(prepared_statement_handle_t&&) = default;

				~prepared_statement_handle_t()
				{
                    /*if(_skeleton_stmt)
                    {
                        delete _skeleton_stmt;
                        _skeleton_stmt = nullptr;
                    }*/
				}

				bool operator!() const
				{
					return !_skeleton_stmt;
				}
			};

        }
	}
}




