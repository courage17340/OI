var
  s,s1:ansistring;
  n,i:longint;
  x:longint;
  f:array[0..300] of string;
function yes(s:string):boolean;
var i:longint;
begin
  yes:=true;
  for i:=1 to n do if f[i]=s then exit(false);
end;
begin
  readln(n);
  readln(s);
  for i:=1 to n do f[i]:=s[i];
  f[0]:=' ';
  s1:='';
  readln(s);
  x:=0;
  for i:=1 to length(s) do
    case s[i] of
      '0'..'9':
         begin
           x:=x*10+ord(s[i])-48;
           if (x=0)and yes(s1) then begin inc(n);f[n]:=s1;end;
           if x=0 then s1:='';
         end;
      '-':begin
            write(f[x]);
            if x>0 then s1:=s1+f[x];
            x:=0;
          end;
      end;
  write(f[x]);
  writeln;
end.