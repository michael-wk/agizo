#!/bin/bash


# checking if a build folder has been specified
if [[ -z "$1" ]]; then
    echo "BUILD ERR : Unspecified build target directory."
    exit 1;
fi

echo "__________________________________________"
echo "*makescript*"

echo "> Creating build directory at ./$1"
mkdir -p "$1"/temp/loc
mkdir -p "$1"/temp/t1

# vars:
include_lib="agizo/include"
src_dir="agizo/source"
build_dir="$1"

main_dir="agizo"
main_src="main"

t1_dir="test_1"

assembled_count=0
err=0;


declare -a sources=(
    "dtypes"
    "evaluator"
    "file"
    "lexer"
    "parser"
    "agizo"
)



# checks build folder metadata to see if the file has been modified
# if file doesn't exist, just returning true
needs_build() 
{
    # if no object file exists, must need building
    if [[ ! -e $3/$1.o ]]; then
        return 0
    fi
    # comparing timestamps
    local src_t
    local obj_t 
    src_t=$(stat -c %Y "$2/$1.c")
    obj_t=$(stat -c %Y "$3/$1.o")

    #echo "TSTAMPS : $src_t | $obj_t"
    if (( src_t >= obj_t )); then
        return 0
    fi
    return 1
}



# assembles sources, keeps object files
# writes to metadata file on previous timestamp of file modified

assemble()
{
    for key in "${!sources[@]}"
    do
        # if the file has been edited or doesn't exist
        
        if needs_build "${sources[$key]}" "$src_dir" "$build_dir"/temp == 0; then
            echo "> Assembling source['$key'] : '${sources[$key]}.c'"
            if ! gcc -I"$include_lib" \
                -c "$src_dir/${sources[$key]}.c" \
                -o "$build_dir/temp/${sources[$key]}.o"; 
            then
                (( err++ ))
            fi
            
            # don't rebuild on gcc error
            #if [[ $? -ne 0 ]]; then
            #    error++
            #fi
            (( assembled_count++ ))
            
        fi
    done

    # main assembled separately (not in source dir)
    if needs_build "${main_src}" "$main_dir" "$build_dir"/temp/loc ==0; then
        
        echo "> Assembling source : '${main_src}.c''"
        if ! gcc -I"$include_lib" \
            -c "$main_dir/${main_src}.c" \
            -o "$build_dir/temp/loc/${main_src}.o";
        then
            (( err++ ))
        fi
        (( assembled_count++ ))
    fi

    echo "> Finished assembling."
}


link_program()
{
    
    echo "> Linking"
    if ! gcc "$build_dir"/temp/*.o "$build_dir"/temp/loc/main.o -o "$build_dir"/agizo.out; then
        echo "> Build failed at link stage"
    fi
}



assemble


echo "> Assembled count : "${assembled_count}
if (( err > 0 )); then
    echo "> Build failed : $err files could not be built" 
    exit
fi

if (( assembled_count <= 0 )); then
    echo "> No work to do"
else
    link_program
fi


if [[ $2 == "t1" ]]; then
    echo "__________________________________________"
    echo "*test_1 build*"

    if needs_build "${main_src}" "${t1_dir}" "$build_dir"/temp/t1; then
        gcc -I"$include_lib" -c test_1/main.c -o "$build_dir"/temp/t1/main.o
    fi

    gcc "$build_dir"/temp/*.o "$build_dir"/temp/t1/main.o -o "$build_dir"/test1.out

    #gcc -I$include_lib $(find "$build_dir/temp" -name '*.o' ! -name 'main.o') test_1/main.c -o build/test_1.out
    
fi

exit

# building obj files for azigo












