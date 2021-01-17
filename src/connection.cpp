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
#include <sqlpp11/skeleton/connection.h>
#include "detail/prepared_statement_handle.h"
#include "detail/result_handle.h"
#include "detail/connection_handle.h"

namespace sqlpp
{
	namespace skeleton
	{

        void execute_prepared_statement(detail::prepared_statement_handle_t& prepared_statement)
        {
            
        }

        void execute_statement(detail::connection_handle_t& handle, const std::string& statement)
        {
			handle._db.direct_exec(statement.c_str());
        }

		connection::connection(connection_config config):
			_handle(new detail::connection_handle_t(config))
		{
			
		}

		connection::~connection()
		{
			// FIXME
		}

		char_result_t connection::select_impl(const std::string& statement)
		{
			auto _stream = std::make_shared<otl_stream>(50, statement.c_str(), _handle->_db, otl_explicit_select, "");
            std::unique_ptr<detail::result_handle> result_handle(
                new detail::result_handle(_stream, _handle->_conf.debug));
            return { std::move(result_handle) };
		}

		bind_result_t connection::run_prepared_select_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
            return prepared_statement._handle;
		}

		size_t connection::run_prepared_insert_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
			return 0; //fix me
		}

		size_t connection::run_prepared_update_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
			return 0; //fix me
		}

		size_t connection::run_prepared_remove_impl(prepared_statement_t& prepared_statement)
		{
            execute_prepared_statement(*prepared_statement._handle);
			return 0; //fix me
		}

		prepared_statement_t connection::prepare_impl(const std::string& statement, size_t no_of_parameters, size_t no_of_columns)
		{
			auto _stream = std::make_shared<otl_stream>(50, statement.c_str(), _handle->_db,  otl_explicit_select, "");

			return { std::unique_ptr<detail::prepared_statement_handle_t>(
				new detail::prepared_statement_handle_t(_stream, no_of_parameters, no_of_columns, true)) };
		}

		size_t connection::insert_impl(const std::string& statement)
		{
			execute_statement(*_handle, statement);
            return 0; //fix me
		}

		void connection::execute(const std::string& command)
		{
			execute_statement(*_handle, command);
		}

		size_t connection::update_impl(const std::string& statement)
		{
            execute_statement(*_handle, statement);
            return 0; //fix me
		}

		size_t connection::remove_impl(const std::string& statement)
		{
            execute_statement(*_handle, statement);
            return 0; //fix me
		}

		std::string connection::escape(const std::string& s) const
		{
            std::string t;
            size_t count(s.size());
            for (auto c : s) {
                if (c == '\'') {
                    count++;
                }
            }
            t.reserve(count);
            for (auto c : s) {
                if (c == '\'') {
                    t.push_back(c);
                }
                t.push_back(c);
            }
            return t;
		}

		void connection::start_transaction()
		{
			//fix me
		}

		void connection::commit_transaction()
		{
			//fix me
		}

		void connection::rollback_transaction(bool report)
		{
			//fix me
		}

		void connection::report_rollback_failure(const std::string message) noexcept
		{
			//fix me
		}
	}
}

