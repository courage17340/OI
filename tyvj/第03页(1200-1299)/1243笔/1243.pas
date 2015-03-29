type
  arr=record
        name:string;
        z:array[0..15] of longint;
      end;
var
  a:array[0..100000] of arr;
  n,m,p,q,i,j:longint;
  ch:char;
procedure quicksort(m,n:longint);
var
  i,j,x:longint;
  temp:arr;
begin
  x:=a[(m+n) div 2].z[q];
  i:=m;
  j:=n;
  repeat
    while a[i].z[q]>x do i:=i+1;
    while a[j].z[q]<x do j:=j-1;
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
  readln(n,m,p,q);
  for i:=1 to n do
    begin
      a[i].name:='';
      repeat
        read(ch);
        if ch<>' ' then a[i].name:=a[i].name+ch;
        until ch=' ';
      for j:=1 to p do read(a[i].z[j]);
      readln;
    end;
  quicksort(1,n);
  for i:=1 to m do writeln(a[i].name);
end.