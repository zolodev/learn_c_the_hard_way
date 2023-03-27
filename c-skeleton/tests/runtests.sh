# TODO: script to run tests
echo "Running unit tests:"

LOG_FILE=tests/tests.log

for i in tests/*_tests
do
    if test -f $i
    then
        if $VALGRIND ./$i 2>> $LOG_FILE
        then
            echo $i PASS
        else
            echo "ERROR in test $i: here's $LOG_FILE"
            echo "-----"
            tail $LOG_FILE
            exit 1
        fi
    fi
done

echo ""