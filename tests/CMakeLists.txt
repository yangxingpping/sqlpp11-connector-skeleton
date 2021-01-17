macro (build_and_run arg)
	# Add headers to sources to enable file browsing in IDEs

	IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	link_libraries(odbc32)
	ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")

	ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")

	add_executable("Sqlpp11Skeleton${arg}" "${arg}.cpp" ${sqlpp_headers})
	target_link_libraries("Sqlpp11Skeleton${arg}"  PUBLIC sqlpp-skeleton ) #PUBLIC Sqlpp11
	#target_link_libraries("Sqlpp11Skeleton${arg}" nativeclient)
	add_test("Sqlpp11Skeleton${arg}" "${arg}")
endmacro ()

build_and_run(SkeletonTest)
