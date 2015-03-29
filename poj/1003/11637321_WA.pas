var
  a:array[0..300] of double;
  i:longint;
  x:double;
function f(x:double):longint;
var
  i,j,m:longint;
begin
  i:=1;
  j:=300;
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
  for i:=0 to 300 do a[i]:=0;
  for i:=1 to 300 do a[i]:=a[i-1]+1/(i+1);
  readln(x);
  while x>0 do
    begin
      writeln(f(x),' card(s)');
      readln(x);
    end;
end.