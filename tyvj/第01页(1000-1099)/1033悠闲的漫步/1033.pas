type
  arr=record
         l,r:longint;
       end;
var
  a:array[1..1000] of arr;
  i,n,j:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
function f(num:longint):longint;
begin
  if (a[num].l=0)and(a[num].r=0) then exit(0);
  if a[num].l=0 then f:=f(a[num].r)+1 else
  if a[num].r=0 then f:=f(a[num].l)+1 else
  f:=max(f(a[num].l),f(a[num].r))+1;
end;
begin
  readln(n);
  for i:=1 to n-1 do
    begin
      read(j);
      readln(a[j].l,a[j].r);
    end;
  writeln(f(1)+1);
end.