type
  arr=record
        num,v:longint;
      end;
var
  a:array[0..50000] of arr;
  n,p,i,j,x,y:longint;
procedure sort(m,n:longint);
var
  i,j,x:longint;
  temp:arr;
begin
  x:=a[(m+n) div 2].v;
  i:=m;
  j:=n;
  repeat
    while a[i].v<x do i:=i+1;
    while a[j].v>x do j:=j-1;
    if i<=j then
      begin
        temp:=a[i];
        a[i]:=a[j];
        a[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then sort(m,j);
  if i<n then sort(i,n);
end;
begin
  readln(n,p);
  for i:=1 to n do begin read(a[i].v);a[i].num:=i;end;readln;
  sort(1,n);
  for i:=1 to p do
    begin
      readln(x,y);
      for j:=n downto 1 do if (a[j].num>=x)and(a[j].num<=y) then break;
      write(a[j].v,' ');
      for j:=1 to n do if (a[j].num>=x)and(a[j].num<=y) then break;
      writeln(a[j].v);
    end;
  readln;
end.