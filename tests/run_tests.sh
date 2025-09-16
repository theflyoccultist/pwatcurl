#!/usr/bin/env bash
set -e

while read url; do
  fname=$(echo "$url" | sed 's|[^a-zA-Z0-9]|_|g')

  echo "Testing $url ..."

  ./pwatcurl "$url" >"out.tmp" 2>/dev/null
  code=$?

  if [ -f "expected/$fname.code" ]; then
    expected_code=$(car "expected/$fname.code")
    echo "expected code: $expected_code | Got: $code"
  fi

  diff -q "expected/$fname.out" "out.tmp" || echo "Output mismatch for $url"

  rm -f out.tmp
done <urls.txt
