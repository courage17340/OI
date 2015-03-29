var
  a:array[1..4] of longint;
  x,n,i,j:longint;
function f(x:longint):longint;
var
  t,i,j,n:longint;
begin
  n:=0;
  while x>0 do
    begin
      inc(n);
      a[n]:=x mod 10;
      x:=x div 10;
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
  f:=0;
  for i:=1 to n do f:=f*10+a[i];
end;
function g(x:longint):longint;
var
  t,i,j,n:longint;
begin
  n:=0;
  while x>0 do
    begin
      inc(n);
      a[n]:=x mod 10;
      x:=x div 10;
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
  g:=0;
  for i:=1 to n do g:=g*10+a[i];
end;
begin
  while true do
    begin
      readln(x);
      if x=-1 then break;
      writeln('N=',x,':');
      if (x<1000)or(x>9999)or(f(x)=g(x)) then
        begin
          writeln('No!!');
          continue;
        end;
      n:=0;
      while (x<>6174)and(x<>0) do
        begin
          writeln(f(x),'-',g(x),'=',f(x)-g(x));
          x:=f(x)-g(x);
          inc(n);
        end;
      writeln('Ok!! ',n,' times');
    end;
end.