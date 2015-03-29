var
  a:array[1..30000] of longint;
  n,i,j,ans,w:longint;
procedure sort(m,n:longint);
var
  i,j,x,t:longint;
begin
  x:=a[(m+n) shr 1];
  i:=m;
  j:=n;
  repeat
    while a[i]>x do inc(i);
	while a[j]<x do dec(j);
	if i<=j then
	  begin
	    t:=a[i];
		a[i]:=a[j];
		a[j]:=t;
		inc(i);
		dec(j);
      end;
  until i>j;
  if i<n then sort(i,n);
  if m<j then sort(m,j);
end;
begin
  readln(w);
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  i:=1;
  j:=n;
  ans:=0;
  while i<=j do
    begin
	  if a[i]+a[j]<=w then dec(j);
	  inc(i);
	  inc(ans);
	end;
  writeln(ans);
end.