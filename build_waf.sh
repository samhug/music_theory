#!/bin/bash

WAF_VERSION=1.7.5
WAF_EXTRAS=boost,doxygen,unittest_gtest


WAF_PACKAGE=waf-$WAF_VERSION
TEMP_DIR=`mktemp -d`

# Download the waf source code
wget http://waf.googlecode.com/files/$WAF_PACKAGE.tar.bz2 -O - | tar xj --directory="$TEMP_DIR"

# Build waf
pushd $TEMP_DIR/$WAF_PACKAGE
python waf-light --tools=$WAF_EXTRAS
popd

# Copy the waf binary to our project directory
cp $TEMP_DIR/$WAF_PACKAGE/waf .

# Remove the temporary files
rm -rf $TEMP_DIR

# Download third-party extras
wget http://github.com/tanakh/waf-unittest/raw/master/unittest_gtest.py
