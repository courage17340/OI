type
  arr=record
        name:string;
        num:longint;
      end;
var
  a:array[0..20000] of arr;
  n,m,i,j,x:longint;
  s:string;
function check:boolean;
var
  i:longint;
begin
  check:=false;
  for i:=1 to j do if a[i].name=s then begin x:=i;exit(true);end;
end;
procedure quicksort(m,n:longint);
var
  i,j:longint;
  x:string;
  temp:arr;
begin
  x:=a[(m+n) div 2].name;
  i:=m;
  j:=n;
  repeat
    while a[i].name<x do i:=i+1;
    while a[j].name>x do j:=j-1;
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
var x:longint;
begin
  if (m>n)or(m=n)and(a[m].name<>s) then exit(0);
  if a[m].name=s then exit(a[m].num);
  if a[n].name=s then exit(a[n].num);
  x:=(m+n) div 2;
  if a[x].name=s then exit(a[x].num);
  if a[x].name>s then find:=find(m+1,x-1)
                 else find:=find(x+1,n-1);
end;
begin
  readln(n);
  j:=0;
  for i:=1 to n do
    begin
      readln(s);
      if check
        then inc(a[x].num)
        else
          begin
            inc(j);
            a[j].name:=s;
            a[j].num:=1;
          end;
    end;
  n:=j;
  quicksort(1,n);
  readln(m);
  for i:=1 to m do
    begin
      readln(s);
      writeln(find(1,n));
    end;
end.