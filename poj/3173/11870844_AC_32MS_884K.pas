var
  a:array[1..20,1..20] of longint;
  n,i,j,x:longint;
function next(x:longint):longint;
begin
  exit(x mod 9+1);
end;
begin
  readln(n,x);
  for i:=1 to n do
    for j:=1 to i do
      begin
        a[j,i]:=x;
        x:=next(x);
      end;
  for i:=1 to n do
    begin
      for j:=1 to i-1 do write('  ');
      for j:=i to n-1 do write(a[i,j],' ');
      writeln(a[i,n]);
    end;
end.