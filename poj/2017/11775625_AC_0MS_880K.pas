type rec=record t,s:longint;end;
var
  a:array[0..10] of rec;
  x:rec;
  n,i,j,s:longint;
begin
  fillchar(a,sizeof(a),0);
  while true do
    begin
      readln(n);
      if n=-1 then break;
      for i:=1 to n do readln(a[i].s,a[i].t);
      for i:=1 to n-1 do
        for j:=i+1 to n do
          if a[i].t>a[j].t then
            begin
              x:=a[i];a[i]:=a[j];a[j]:=x;
            end;
      s:=0;
      for i:=1 to n do s:=s+(a[i].t-a[i-1].t)*a[i].s;
      writeln(s,' miles');
    end;
end.