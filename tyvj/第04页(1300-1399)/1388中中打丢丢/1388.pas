type
  arr=record num,rp:longint;end;
var
  a:array[0..100000] of arr;
  n,i,j,k:longint;
procedure quicksort(m,n:longint);
var
  i,j,x:longint;
  temp:arr;
begin
  x:=a[(m+n) div 2].rp;
  i:=m;
  j:=n;
  repeat
    while a[i].rp<x do i:=i+1;
    while a[j].rp>x do j:=j-1;
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
begin
  read(n);
  for i:=1 to n do begin read(a[i].rp);a[i].num:=i;end;
  read(k);
  quicksort(1,n);
  writeln(a[k].num);
end.