#!/bin/bash
PATH=`pwd`
while read declline
do
	CDECL_OUT=`/usr/bin/cdecl explain $declline`
	DECL_OUT=`$PATH/bin/decl <<< $declline` 
	printf "$declline\ncdecl: $CDECL_OUT\ndecl: $DECL_OUT\n\n" 
done < ch-5/decl/decl-test.txt 
