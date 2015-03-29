var
  a,b:array[0..100000] of longint;
  m,n,i,j,ans:longint;
procedure sort1(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=a[(m+n) div 2];
  i:=m;
  j:=n;
  repeat
    while a[i]<x do i:=i+1;
    while a[j]>x do j:=j-1;
    if i<=j then
      begin
        temp:=a[i];
        a[i]:=a[j];
        a[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then sort1(m,j);
  if i<n then sort1(i,n);
end;
procedure sort2(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=b[(m+n) div 2];
  i:=m;
  j:=n;
  repeat
    while b[i]<x do i:=i+1;
    while b[j]>x do j:=j-1;
    if i<=j then
      begin
        temp:=b[i];
        b[i]:=b[j];
        b[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then sort2(m,j);
  if i<n then sort2(i,n);
end;
begin
  readln(m,n);
  if m>=n then begin writeln(0);halt;end;
  for i:=1 to m do read(b[i]);
  for i:=1 to n do read(a[i]);
  sort1(1,n);sort2(1,m);
  i:=1;
  j:=1;
  ans:=0;
  while (i<=n)and(j<=m) do
    if a[i]>b[j]
      then begin inc(i);inc(j);end
      else begin ans:=ans+a[i];inc(i);end;
  if (i>n)and(j<=m) then begin writeln(0);halt;end;
  for j:=i to n do ans:=ans+a[j];
  writeln(ans);
end.