type
  arr=record
        score:extended;
        name:string;
      end;
var
  a:array[0..100000] of arr;
  n,m,i,j:longint;
  ch:char;
  s:string;
  sc:extended;
procedure quicksort(m,n:longint);
var
  i,j:longint;
  x:extended;
  temp:arr;
begin
  x:=a[(m+n) div 2].score;
  i:=m;
  j:=n;
  repeat
    while a[i].score<x do i:=i+1;
    while a[j].score>x do j:=j-1;
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
function find(m,n:longint):longint;
var
  x:longint;
begin
  if (m>n)or(m=n)and(a[m].score<>sc) then exit(0);
  if a[m].score=sc then exit(m);
  if a[n].score=sc then exit(n);
  x:=(m+n) div 2;
  if a[x].score=sc then exit(x);
  if a[x].score>sc then exit(find(m+1,x-1)) else exit(find(x+1,n-1));
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      s:='';
      repeat
        read(ch);
        if ch<>' ' then s:=s+ch;
        until ch=' ';
      readln(a[i].score);
      a[i].name:=s;
    end;
  quicksort(1,n);
  readln(m);
  for i:=1 to m do
    begin
      readln(sc);
      j:=find(1,n);
      if j=0 then writeln('No Such User')
             else writeln(a[j].name,' ',j);
    end;
end.