var
  a,i:longint;
  b:array[0..15] of longint;
  s:ansistring;
procedure work(x:longint);
var
  t:longint;
begin
  if x=0 then s:=s+'0';
  if x=1 then begin s:=s+'2(0)';exit;end;
  if x=2 then begin s:=s+'2';exit;end;
  while x>0 do
    begin
      t:=trunc(ln(x)/ln(2));
      if t=1 then begin s:=s+'2+';x:=x-2;end else
        begin
          s:=s+'2(';
          work(t);
          x:=x-b[t];
          s:=s+')+';
        end;
    end;
  if s[length(s)]='+' then delete(s,length(s),1);
end;
begin
  b[0]:=1;
  for i:=1 to 15 do b[i]:=b[i-1]*2;
  readln(a);
  s:='';
  work(a);
  writeln(s);
end.