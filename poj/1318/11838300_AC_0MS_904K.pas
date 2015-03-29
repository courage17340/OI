type rec=record s:string;f:array[1..26] of longint;end;
var
  a:array[1..100] of rec;
  n,i,j:longint;
  s:string;
  t:rec;
  p:boolean;
function yes(s:string;k:longint):boolean;
var
  i:longint;
  f:array[1..26] of longint;
begin
  fillchar(f,sizeof(f),0);
  for i:=1 to length(s) do
    inc(f[ord(s[i])-96]);
  for i:=1 to 26 do if f[i]<>a[k].f[i] then exit(false);
  exit(true);
end;
begin
  i:=0;
  while true do
    begin
      readln(s);
      if s='XXXXXX' then break;
      inc(i);
      a[i].s:=s;
      fillchar(a[i].f,sizeof(a[i].f),0);
      for j:=1 to length(s) do inc(a[i].f[ord(s[j])-96]);
    end;
  n:=i;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i].s>a[j].s then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
  while true do
    begin
      readln(s);
      if s='XXXXXX' then break;
      p:=false;
      for i:=1 to n do if yes(s,i) then
        begin
          p:=true;
          writeln(a[i].s);
        end;
      if not p then writeln('NOT A VALID WORD');
      writeln('******');
    end;
end.