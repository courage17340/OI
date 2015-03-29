type
  rec=record
        s:string;
        v:longint;
      end;
var
  a:array[0..100] of rec;
  t:rec;
  m,n,i,j,k:longint;
begin
  readln(n,m);
  for i:=1 to m do
    begin
      readln(a[i].s);
      a[i].v:=0;
      for j:=1 to n-1 do
        for k:=j+1 to n do
          if a[i].s[j]>a[i].s[k] then inc(a[i].v);
    end;
  for i:=1 to m-1 do
    for j:=1 to m-i do
      if a[j].v>a[j+1].v then
        begin
          t:=a[j];
          a[j]:=a[j+1];
          a[j+1]:=t;
        end;
  for i:=1 to m do writeln(a[i].s);
end.