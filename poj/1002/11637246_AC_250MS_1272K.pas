var
  a:array[0..100010] of longint;
  n,i,j,x:longint;
  s:string;
  flag:boolean;
function num(x:char):longint;
begin
  case x of
    '0'..'9':exit(ord(x)-48);
    'A'..'C':exit(2);
    'D'..'F':exit(3);
    'G'..'I':exit(4);
    'J'..'L':exit(5);
    'M'..'O':exit(6);
    'P','R','S':exit(7);
    'T'..'V':exit(8);
    'W'..'Y':exit(9);
  end;
end;

function f(x:longint):string;
begin
  str(x,f);
  while length(f)<7 do f:='0'+f;
  exit(copy(f,1,3)+'-'+copy(f,4,4)+' ');
end;

procedure sort(m,n:longint);
var
  i,j,t,x:longint;
begin
  x:=a[(m+n) shr 1];
  i:=m;j:=n;
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
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

begin
  flag:=true;
  readln(n);
  fillchar(a,sizeof(a),0);
  a[0]:=-1;
  a[n+1]:=maxlongint;
  for i:=1 to n do
    begin
      readln(s);
      x:=0;
      for j:=1 to length(s) do
        if s[j]<>'-' then
          x:=x*10+num(s[j]);
      a[i]:=x;
    end;
  sort(1,n);
  j:=1;x:=1;
  for i:=2 to n+1 do
    if a[j]=a[i]
      then inc(x)
      else
        begin
          if x>1 then
            begin
              writeln(f(a[j]),x);
              flag:=false;
            end;
          x:=1;
          j:=i;
        end;
  if flag then writeln('No duplicates.');
end.