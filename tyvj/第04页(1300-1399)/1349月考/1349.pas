var
  a:array[0..100000] of string;
  n,m,i,j:longint;
  s:string;
procedure quicksort(m,n:longint);
var
  i,j:longint;
  x,temp:string;
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
  if m<j then quicksort(m,j);
  if i<n then quicksort(i,n);
end;
function search(m,n:longint):longint;
var
  i:longint;
begin
  if m>n then exit(0);
  if m=n then if a[m]=s then exit(1) else exit(0);
  i:=(m+n) div 2;
  if a[i]<s then search:=search(i+1,n);
  if a[i]>s then search:=search(m,i-1);
  if a[i]=s then exit(1);
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  quicksort(1,n);
  readln(m);
  j:=0;
  for i:=1 to m do
    begin
      readln(s);
      j:=j+search(1,n);
    end;
  writeln(j);
end.