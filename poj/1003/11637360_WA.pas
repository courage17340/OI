const max=1000;
var
  a:array[0..max] of real;
  i:longint;
  x:real;
function f(x:real):longint;
var
  i,j,m:longint;
begin
  i:=1;
  j:=max;
  m:=(i+j) shr 1;
  while i<j do
    begin
      if a[m]<x then i:=m+1;
      if a[m]>x then j:=m-1;
      m:=(i+j) shr 1;
    end;
  exit(m);
end;
begin
  for i:=0 to max do a[i]:=0;
  for i:=1 to max do a[i]:=a[i-1]+1/(i+1);
  readln(x);
  while x>0 do
    begin
      writeln(f(x),' card(s)');
      readln(x);
    end;
end.