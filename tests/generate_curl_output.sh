while read url; do
	fname=$(echo "$url" | sed 's|[^a-zA-Z0-9]|_|g')
	curl -s -o "expected/$fname.out" -w "%{http_code}" "$url" > "expected/$fname.code"
done < urls.txt
