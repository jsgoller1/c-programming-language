#!/bin/bash
while read declline
do
	bin/decl <<< $declline 
done < ch-5/decl/decl-test.txt 
