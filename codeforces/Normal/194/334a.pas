var
  a:array[1..100,1..100] of longint;
  n,i,j,k,p,q:longint;
function next(x:longint):longint;
begin
  if x=n then exit(1);
  exit(x+1);
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      a[i,j]:=(i-1)*n+j;
  for i:=1 to n do
    begin
      p:=i;
      q:=1;
      write(a[p,q]);
      for j:=2 to n do
        begin
          p:=next(p);
          q:=next(q);
          write(' ',a[p,q]);
        end;
      writeln;
    end;
end.