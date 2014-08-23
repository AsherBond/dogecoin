#!/bin/sh
<<<<<<< HEAD

=======
if [ $# -gt 1 ]; then
    cd "$2"
fi
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
if [ $# -gt 0 ]; then
    FILE="$1"
    shift
    if [ -f "$FILE" ]; then
        INFO="$(head -n 1 "$FILE")"
    fi
else
<<<<<<< HEAD
    echo "Usage: $0 <filename>"
    exit 1
fi

if [ -e "$(which git)" ]; then
=======
    echo "Usage: $0 <filename> <srcroot>"
    exit 1
fi

DESC=""
LAST_COMMIT_DATE=""
if [ -e "$(which git)" -a -d ".git" ]; then
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
    # clean 'dirty' status of touched files that haven't been modified
    git diff >/dev/null 2>/dev/null 

    # get a string like "v0.6.0-66-g59887e8-dirty"
    DESC="$(git describe --dirty 2>/dev/null)"

    # get a string like "2012-04-10 16:27:19 +0200"
<<<<<<< HEAD
    TIME="$(git log -n 1 --format="%ci")"
=======
    LAST_COMMIT_DATE="$(git log -n 1 --format="%ci")"
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
fi

if [ -n "$DESC" ]; then
    NEWINFO="#define BUILD_DESC \"$DESC\""
else
    NEWINFO="// No build information available"
fi

# only update build.h if necessary
if [ "$INFO" != "$NEWINFO" ]; then
    echo "$NEWINFO" >"$FILE"
<<<<<<< HEAD
    echo "#define BUILD_DATE \"$TIME\"" >>"$FILE"
=======
    if [ -n "$LAST_COMMIT_DATE" ]; then
        echo "#define BUILD_DATE \"$LAST_COMMIT_DATE\"" >> "$FILE"
    fi
>>>>>>> 20c2a7ecbb53d034a01305c8e63c0ee327bd9917
fi
