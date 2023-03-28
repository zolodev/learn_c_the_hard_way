# TODO: script to run tests
echo "Running unit tests:"

RED='\033[0;31m'
C_GREEN_BOLD="\033[0;32;1m"
C_RESET="\033[0m"

LOG_FILE=tests/tests.log


for i in tests/*_tests
do
    if test -f $i
    then
        if $VALGRIND ./$i 2>> $LOG_FILE
        then
            echo ${C_GREEN_BOLD}$i PASS ${C_RESET}
        else
            echo ${RED} "ERROR in test $i: here's $LOG_FILE" ${C_RESET}
            echo "-----"
            tail $LOG_FILE
            exit 1
        fi
    fi
done

echo ""