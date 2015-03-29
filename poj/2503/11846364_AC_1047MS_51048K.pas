type rec=record x,y:string;end;
var
  a:array[0..100000] of rec;
  n,i,j:longint;
  s,t:string;
procedure sort(m,n:longint);
var
  x:string;
  t:rec;
  i,j:longint;
begin
  x:=a[(m+n) shr 1].x;
  i:=m;
  j:=n;
  repeat
    while a[i].x<x do inc(i);
    while a[j].x>x do dec(j);
    if i<=j then
      begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
        inc(i);
        dec(j);
      end;
  until i>j;
  if i<n then sort(i,n);
  if m<j then sort(m,j);
end;
function find(s:string;L,r:longint):longint;
var
  m:longint;
begin
  m:=(L+r) shr 1;
  if a[m].x=s then exit(m);
  if L>=r then exit(0);
  if a[m].x<s then exit(find(s,m+1,r));
  exit(find(s,L,m-1));
end;
begin
  a[0].y:='eh';
  n:=0;
  while true do
    begin
      readln(s);
      if s='' then break;
      inc(n);
      t:=copy(s,1,pos(' ',s)-1);
      delete(s,1,pos(' ',s));
      a[n].x:=s;
      a[n].y:=t;
    end;
  sort(1,n);
  while not eof do
    begin
      readln(s);
      writeln(a[find(s,1,n)].y);
    end;
end.